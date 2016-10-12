<include src="include/header"/>

<a href="/admin/group/new/{$session['token']}" class="button right">Nouveau groupe</a>
<table class="table">
	<thead>
		<tr>
			<th class="matricule">Id</th>
			<th>Nom</th>
			<th class="action">Actions</th>
		<tr>
	</thead>
	<tbody>
		<foreach loop="$groups as $data">
			<tr>
				<td>{$data['id']}</td>
				<td><a href="/admin/group/see/{$data['id']}">{$data['name']}</a></td>
				<td class="action">
					<a href="/admin/group/edit/{$data['id']}/{$session['token']}"><span class="fa fa-pencil"></span></a>
					<a href="/admin/group/delete/{$data['id']}/{$session['token']}"><span class="fa fa-times"></span></a>
				</td>
			</tr>
		</foreach>
	<tbody>
</table>

<include src="include/footer"/>