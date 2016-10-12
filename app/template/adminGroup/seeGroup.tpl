<include src="include/header"/>

<table class="table">
	<thead>
		<tr>
			<th class="matricule">Matricule</th>
			<th>Nom</th>
			<th>Email</th>
			<th>Contact</th>
			<th>Professeur</th>
		<tr>
	</thead>
	<tbody>
		<foreach loop="$students as $data">
			<tr>
				<td>{$data['id']}</td>
				<td>
					<a href="/admin/student/see/{$data['id']}">{$data['personDetail']['firstName']} - {$data['personDetail']['name']}</a>
				</td>
				<td>{$data['personDetail']['email']}</td>
				<td>{$data['contact']['personDetail']['firstName']} - {$data['contact']['personDetail']['name']}</td>
				<td>{$data['teacher']['personDetail']['firstName']} - {$data['teacher']['personDetail']['name']}</td>
			</tr>
		</foreach>
	<tbody>
</table>

<include src="include/footer"/>